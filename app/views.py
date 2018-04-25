import json
from app import app, models, db
from flask import Flask, render_template, url_for, request, session, redirect
import datetime

#QT
#QT
application = Flask(__name__)

@app.route('/postjson', methods = ['POST'])
def postJsonHandler():
    print (request.is_json)

    userNameR = request.get_json()['userName']
    employeeNameR = request.get_json()['employeeName']
    screeningR = request.get_json()['screening']
    priceR = request.get_json()['price']
    pricePaidR = request.get_json()['pricePaid']
    changeR = request.get_json()['change']
    a = models.Receipts(userName=userNameR, employeeName=employeeNameR , screening=screeningR,price=priceR,pricePaid=pricePaidR,change=changeR, transactionTime= datetime.datetime.utcnow())

    db.session.add(a)
    db.session.commit()
    return 'JSON posted'

@app.route('/postjsonR', methods = ['POST'])
def postJsonHandlerR():
    print (request.is_json)
    screeningR = request.get_json()['screening']
    rowReservedIDR = request.get_json()['rowReservedID']
    seatNumberReservedIDR = request.get_json()['seatNumberReservedID']
    a = models.Seat_Reserved(screening=screeningR, rowReservedID=rowReservedIDR, seatNumberReservedID=seatNumberReservedIDR)

    db.session.add(a)
    db.session.commit()
    return 'JSON posted'

@app.route("/employee.json")
def Employee_data():
    data = {"employee" : [ i.as_dict() for i in models.Employee.query.all() ]}
    response = application.make_response(json.dumps(data))
    response.mimetype = "application/json"
    return response

@app.route("/movies.json")
def Movies_data():
    data = {"movies" : [ i.as_dict() for i in models.Movies.query.all() ]}
    response = application.make_response(json.dumps(data))
    response.mimetype = "application/json"
    return response

@app.route("/screens.json")
def Screens_data():
    data = {"screens" : [ i.as_dict() for i in models.Screenings.query.all() ]}
    response = application.make_response(json.dumps(data, default=str))
    response.mimetype = "application/json"
    return response

@app.route("/screen.json")
def screen_data():
    data = {"screen" : [ i.as_dict() for i in models.Screen.query.all() ]}
    response = application.make_response(json.dumps(data))
    response.mimetype = "application/json"
    return response

@app.route("/seats.json")
def Seats_data():
    data = {"seats" : [ i.as_dict() for i in models.Seats.query.all() ]}
    response = application.make_response(json.dumps(data))
    response.mimetype = "application/json"
    return response

@app.route("/seatreserved.json")
def seatreserved_data():
    data = {"reserved" : [ i.as_dict() for i in models.Seat_Reserved.query.all() ]}
    response = application.make_response(json.dumps(data))
    response.mimetype = "application/json"
    return response

@app.route("/typetickets.json")
def type_of_tickets_data():
    data = {"tickets" : [ i.as_dict() for i in models.TypeOfTickets.query.all() ]}
    response = application.make_response(json.dumps(data))
    response.mimetype = "application/json"
    return response

@app.route("/receipts.json")
def receipts_data():
    data = {"receipt" : [ i.as_dict() for i in models.Receipts.query.all() ]}
    response = application.make_response(json.dumps(data, default=str))
    response.mimetype = "application/json"
    return response


#Web
@app.route('/home', methods=['GET', 'POST'])
def home():
      return render_template('home.html')


@app.route('/nowshowing', methods=['GET', 'POST'])
def viewmovies():
        movies = models.Movies.query.all()
        movieOne = models.Movies.query.get(1)
        movieTwo = models.Movies.query.get(2)
        movieThree = models.Movies.query.get(3)

        movieID = None

        if request.method == 'POST':
            movieID = request.form.get('subject')
            # return redirect(url_for('showtimes'))

        session['movieVar'] = movieID

        if movieID != None:
            return redirect(url_for('showtimes'))


        return render_template('nowshowing.html',
                                movies = movies,
                                movieOne = movieOne,
                                movieTwo = movieTwo,
                                movieThree = movieThree,
                                )


@app.route('/showtimes', methods=['GET', 'POST'])
def showtimes():
        screeningID = None

        if 'movieVar' in session:
            movieID = session['movieVar']
            movieName = models.Movies.query.filter_by(id=movieID).first()
            screenings = models.Screenings.query.filter_by(movies_id = movieID).all()


        else:
            return redirect(url_for('home'))


        if request.method == 'POST':
            screeningID = request.form.get('bookSeat')

        session['scrnVar'] = screeningID

        if screeningID != None:
            return redirect(url_for('booktickets'))



        return render_template('showtimes.html',
                                movieName = movieName,
                                screenings = screenings
                                )


@app.route('/booktickets', methods=['GET', 'POST'])
def booktickets():
        movieID = None
        screeningID = None
        seatID = None
        seatsAll = models.Seats.query.all()

        if 'movieVar' in session:
            movieID = session['movieVar']
            movieName = models.Movies.query.filter_by(id=movieID).first()



        if 'scrnVar' in session:
            screeningID = session['scrnVar']
            screening = models.Screenings.query.filter_by(id=screeningID).first()
            seatsRes = models.Seat_Reserved.query.filter_by(screening=screeningID).all()

        else:
            return redirect(url_for('home'))

        if request.method == 'POST':
            seatID = request.form.get('bookThisSeat')
            wordlist = list(seatID)
            a = models.Seat_Reserved(screening=screeningID, rowReservedID=wordlist[0] , seatNumberReservedID=wordlist[1])
            db.session.add(a)
            db.session.commit()

            return redirect(url_for('booktickets'))

        return render_template('booktickets.html',
                                movieName = movieName,
                                screening = screening,
                                seatsRes = seatsRes,
                                seatsAll = seatsAll,
                                )
