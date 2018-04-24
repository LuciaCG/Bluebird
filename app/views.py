import json
from app import app, models, db
from flask import Flask, render_template, url_for, request, session, redirect

#QT
#QT
application = Flask(__name__)
@app.route("/app.json")
def Employee_data():
    data = [ models.Employee.__repr__(models.Employee) for i in models.Employee.query.all() ]
    response = application.make_response(json.dumps(data))
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
