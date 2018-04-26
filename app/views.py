from app import app, models, db
from datetime import timedelta
from flask_mail import Message, Mail
from flask import Flask, render_template, url_for, request, session, redirect, flash
from .forms import LoginForm, RegistrationForm, SessionForm, AddCardForm, SearchMovieForm
import datetime
import hashlib
import codecs
import qrcode
import json

# @app.before_request
# def make_session_permanent():
#     session.permanent = True
#     app.permanent_session_lifetime = timedelta(seconds=20)

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
    userEmailname = None
    if 'userEmail' in session:
        userEmailname = session['userEmail']
    else:
        session['userEmail'] = 'guest@cinema.com'
        userEmailname = session['userEmail']
    print(session['userEmail'])
    print(userEmailname)


    return render_template('home.html',
                            userEmailname=userEmailname)

@app.route('/login', methods=['GET', 'POST'])
def login():
    # now = datetime.now()
    form = LoginForm()
    form2 = SessionForm()

    if form.validate_on_submit():
        if models.Users.query.filter_by(email=form.name.data).count() == 1:
            user = models.Users.query.filter_by(email=form.name.data).first()
            password = form.password.data
            a = hashlib.sha256()
            a.update(password.encode('utf-8'))
            # auth = models.Teams.authenticate(form.name.data,
            #                                  form.password.data)
            if a.hexdigest() == user.password:
                session['userEmail'] = form.name.data
                return redirect(url_for('home'))
            else:
                flash('Email or Password incorrect')
                return render_template('login.html',
                                    title='Sign In',
                                    form=form)
        else:
            flash('Email or Password incorrect')
            return render_template('login.html',
                                title='Login',
                                form=form,
                                form2=form2)
    else:
        return render_template('login.html',
                            title='Login',
                            form=form,
                            form2=form2)

@app.route('/register', methods=['GET', 'POST'])
def signup():
    form = RegistrationForm()
    if form.validate_on_submit():
        p = models.Users(name=form.name.data,
                        email=form.email.data,
                        password=form.password.data,
                        )
        db.session.add(p)
        db.session.commit()
        return redirect(url_for('login'))
    else:
        return render_template('registration.html',
                            title='Register',
                            form=form)

@app.route('/userPage', methods=['GET', 'POST'])
def userPage():
    form = AddCardForm()
    userEmailname = None
    if 'userEmail' in session:
        userEmailname = session['userEmail']
        user = models.Users.query.filter_by(email=userEmailname).first()
        if form.validate_on_submit():
            if models.CardDetails.query.filter_by(userID=user.id, cardNickname=form.cardNickname.data).count() == 0:
                p = models.CardDetails(userID=user.id,
                                cardNickname=form.cardNickname.data,
                                cardNumber=form.cardNumber.data,
                                exMonth=form.exMonth.data,
                                exYear=form.exYear.data
                                )
                db.session.add(p)
                db.session.commit()
                return redirect(url_for('userPage'))
            else:
                print("nickname not unique")
                return redirect(url_for('userPage'))
    else:
        session['userEmail'] = 'guest@cinema.com'
        userEmailname = session['userEmail']
    return render_template('userpage.html',
                            userEmailname=session['userEmail'],
                            user=user,
                            form=form
                            )

@app.route('/nowshowing', methods=['GET', 'POST'])
def viewmovies():
        form = SearchMovieForm()
        movies = models.Movies.query.all()
        movieOne = models.Movies.query.get(10)
        movieTwo = models.Movies.query.get(13)
        movieThree = models.Movies.query.get(17)
        movieSearch = ""
        session['movieSearch'] = ""
        movieID = None

        userEmailname = None
        if 'userEmail' in session:
            userEmailname = session['userEmail']
        else:
            session['userEmail'] = 'guest@cinema.com'
            userEmailname = session['userEmail']

        if request.method == 'POST':
            movieID = request.form.get('subject')
            # return redirect(url_for('showtimes'))
        if form.validate_on_submit():
            session['movieSearch'] = form.movieName.data
            movieSearch = session['movieSearch']
            print(movieSearch)
            # return redirect(url_for('viewmovies'))

        session['movieVar'] = movieID

        if movieID != None:
            return redirect(url_for('showtimes'))

        return render_template('nowshowing.html',
                                form = form,
                                movies = movies,
                                models = models,
                                movieOne = movieOne,
                                movieTwo = movieTwo,
                                movieThree = movieThree,
                                userEmailname=session['userEmail'],
                                movieSearch = movieSearch
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


        userEmailname = None
        if 'userEmail' in session:
            userEmailname = session['userEmail']
        else:
            session['userEmail'] = 'guest@cinema.com'
            userEmailname = session['userEmail']

        if request.method == 'POST':
            screeningID = request.form.get('bookSeat')

        session['scrnVar'] = screeningID
        session['adult'] = 0
        session['child'] = 0
        session['senior'] = 0
        session['vip'] = 0
        session['totalSeats'] = 0
        session['priceTotal'] = 0

        if screeningID != None:
            session['seatList'] = ['No seats currently selected']
            return redirect(url_for('booktickets'))



        return render_template('showtimes.html',
                                movieName = movieName,
                                screenings = screenings,
                                userEmailname=session['userEmail']
                                )


@app.route('/booktickets', methods=['GET', 'POST'])
def booktickets():
        movieID = None
        screeningID = None
        seatID = None
        seatList = None
        adultTotal = session['adult']
        childTotal = session['child']
        seniorTotal = session['senior']
        vipTotal = session['vip']
        totalSeats = session['totalSeats']
        priceTotal = session['priceTotal']
        adultPlus = 1
        childPlus = 1
        seniorPlus = 1
        vipPlus = 1
        seatList = session['seatList']
        if len(seatList) == 0:
            seatList.append("No seats currently selected")


        # movies = models.Movies.query.all()
        seatsAll = models.Seats.query.all()
        seatNumber = models.Seats.query.with_entities(models.Seats.seatNumber).group_by(models.Seats.seatNumber).all()
        rows = models.Seats.query.with_entities(models.Seats.row).group_by(models.Seats.row).all()

        if 'movieVar' in session:
            movieID = session['movieVar']
            movieName = models.Movies.query.filter_by(id=movieID).first()
        else:
            return redirect(url_for('home'))

        if 'scrnVar' in session:
            screeningID = session['scrnVar']
            screening = models.Screenings.query.filter_by(id=screeningID).first()
            seatsRes = models.Seat_Reserved.query.filter_by(screening=screeningID).all()
        else:
            return redirect(url_for('home'))

        userEmailname = None
        if 'userEmail' in session:
            userEmailname = session['userEmail']
        else:
            session['userEmail'] = 'guest@cinema.com'
            userEmailname = session['userEmail']

        if request.method == 'POST':
            if 'adultPlus' in request.form:
                adultTotal += 1
                priceTotal += 9
                totalSeats += 1
                # session['totalSeats'] =
                session['adult'] = adultTotal
                session['priceTotal'] = priceTotal
                session['totalSeats'] = totalSeats

            elif 'adultMinus' in request.form:
                if totalSeats == 0:
                    seatList.remove(seatList[len(seatList)-1])
                    if len(seatList) == 0:
                        seatList.append("No seats currently selected")
                adultTotal -= 1
                priceTotal -= 9
                totalSeats -= 1
                session['adult'] = adultTotal
                session['priceTotal'] = priceTotal
                session['totalSeats'] = totalSeats


            elif 'childPlus' in request.form:
                childTotal += 1
                priceTotal += 6.5
                totalSeats += 1
                session['child'] = childTotal
                session['priceTotal'] = priceTotal
                session['totalSeats'] = totalSeats


            elif 'childMinus' in request.form:
                if totalSeats == 0:
                    seatList.remove(seatList[len(seatList)-1])
                    if len(seatList) == 0:
                        seatList.append("No seats currently selected")
                childTotal -= 1
                priceTotal -= 6.5
                totalSeats -= 1
                session['child'] = childTotal
                session['priceTotal'] = priceTotal
                session['totalSeats'] = totalSeats


            elif 'seniorPlus' in request.form:
                seniorTotal += 1
                priceTotal += 7
                totalSeats += 1
                session['senior'] = seniorTotal
                session['priceTotal'] = priceTotal
                session['totalSeats'] = totalSeats


            elif 'seniorMinus' in request.form:
                if totalSeats == 0:
                    seatList.remove(seatList[len(seatList)-1])
                    if len(seatList) == 0:
                        seatList.append("No seats currently selected")
                seniorTotal -= 1
                priceTotal -= 7
                totalSeats -= 1
                session['senior'] = seniorTotal
                session['priceTotal'] = priceTotal
                session['totalSeats'] = totalSeats


            elif 'vipPlus' in request.form:
                vipTotal += 1
                priceTotal += 12
                totalSeats += 1
                session['vip'] = vipTotal
                session['priceTotal'] = priceTotal
                session['totalSeats'] = totalSeats


            elif 'vipMinus' in request.form:
                if totalSeats == 0:
                    seatList.remove(seatList[len(seatList)-1])
                    if len(seatList) == 0:
                        seatList.append("No seats currently selected")
                vipTotal -= 1
                priceTotal -= 12
                totalSeats -= 1
                session['vip'] = vipTotal
                session['priceTotal'] = priceTotal
                session['totalSeats'] = totalSeats


            elif 'bookThisSeat' in request.form:
                seatID = request.form.get('bookThisSeat')
                if seatList[0] == 'No seats currently selected':
                    if totalSeats > 0:
                        seatList[0] = seatID
                        totalSeats -= 1
                        session['seatList'] = seatList
                        session['totalSeats'] = totalSeats
                    #    print(totalSeats)
                    #    print(seatList)
                else:
                    if seatID in seatList:
                        seatList.remove(seatID)
                        totalSeats += 1
                        session['seatList'] = seatList
                        session['totalSeats'] = totalSeats
                    #    print(totalSeats)
                    #    print(seatList)

                    else:
                        if totalSeats > 0:
                            seatList.append(seatID)
                            totalSeats -= 1
                            session['seatList'] = seatList
                            session['totalSeats'] = totalSeats
                        #    print(totalSeats)
                        #    print(seatList)


                priceTotal = adultTotal+childTotal+seniorTotal+vipTotal

                return redirect(url_for('booktickets'))

                priceTotal = adultTotal+childTotal+seniorTotal+vipTotal

            elif 'gotoPay' in request.form:
                if totalSeats == 0 and seatList[0] != 'No seats currently selected':
                    session['card'] = "none"
                    return redirect(url_for('payments'))



        return render_template('booktickets.html',
                                movieName = movieName,
                                screening = screening,
                                seatsRes = seatsRes,
                                seatsAll = seatsAll,
                                seatNumber = seatNumber,
                                rows = rows,
                                models = models,
                                adultTotal = adultTotal,
                                adultPlus = adultPlus,
                                childTotal = childTotal,
                                childPlus = childPlus,
                                seniorTotal = seniorTotal,
                                seniorPlus = seniorPlus,
                                vipTotal = vipTotal,
                                vipPlus = vipPlus,
                                priceTotal = priceTotal,
                                seatList = session['seatList'],
                                seatID = seatID,
                                userEmailname=session['userEmail']
                                )


@app.route('/payments', methods=['GET', 'POST'])
def payments():
        movieID = None
        screeningID = None
        seatList = None
        userEmailname = None
        adultTotal = 0
        childTotal = 0
        seniorTotal = 0
        vipTotal = 0
        priceTotal = 0
        seatList = None
        cardDetails = None
        cardDetails2 = None
        newCardNumber = ""
        cardValue = None
        varname = None

        if 'card' in session:
            cardValue = session['card']
        else:
            return redirect(url_for('home'))

        if 'userEmail' in session:
            userEmailname = session['userEmail']
            user = models.Users.query.filter_by(email=userEmailname).first()
            cardDetails = models.CardDetails.query.filter_by(userID=user.id).all()
        else:
            userEmailname = "guest@cinema.com"
            user = models.Users.query.filter_by(email=userEmailname).first()
            cardDetails = models.CardDetails.query.filter_by(userID=user.id).all()

        if 'movieVar' in session:
            movieID = session['movieVar']
            movieName = models.Movies.query.filter_by(id=movieID).first()
            screenings = models.Screenings.query.filter_by(movies_id = movieID).all()
        else:
            return redirect(url_for('home'))

        if 'scrnVar' in session:
            screeningID = session['scrnVar']
            screening = models.Screenings.query.filter_by(id=screeningID).first()
            seatsRes = models.Seat_Reserved.query.filter_by(screening=screeningID).all()
        else:
            return redirect(url_for('home'))

        if 'adult' in session:
            adultTotal = session['adult']
        else:
            return redirect(url_for('home'))

        if 'child' in session:
            childTotal = session['child']
        else:
            return redirect(url_for('home'))

        if 'senior' in session:
            seniorTotal = session['senior']
        else:
            return redirect(url_for('home'))

        if 'vip' in session:
            vipTotal = session['vip']
        else:
            return redirect(url_for('home'))

        if 'priceTotal' in session:
            priceTotal = session['priceTotal']
        else:
            return redirect(url_for('home'))



        # if request.method == 'POST':
        #     screeningID = request.form.get('bookSeat')

        session['scrnVar'] = screeningID

        if request.method == "POST":
            # varname = request.form['Book Now']
            if 'Book Now' not in request.form:
                dropdownCard = request.form['dropdownCard']
                print("card " + dropdownCard)
                print("valie " + cardValue)
                if dropdownCard == "nocard":
                    session['card'] = "nocard"



                else:
                    session['card'] = dropdownCard
                    user = models.Users.query.filter_by(email=userEmailname).first()
                    cardDetails2 = models.CardDetails.query.filter_by(userID=user.id , cardNickname=dropdownCard).first()



                    cardNumber = cardDetails2.cardNumber
                    for character in range(12,16):
                      if (character % 3) == 0:
                        changedLetter = ord(cardNumber[character]) + 3
                      elif (character % 2) == 0:
                        changedLetter = ord(cardNumber[character]) + 2
                      else:
                        changedLetter = ord(cardNumber[character]) + 1
                      newCardNumber += chr(changedLetter)


                      print(newCardNumber)
                      print("else",session['card'])
            # elif varname == "Book Now":
            if 'Book Now' in request.form:
                currentDay = datetime.datetime.now()
                eMonth = request.form['Emonth']
                eyear = request.form['Eyear']
                print(currentDay)
                if eMonth >= currentDay.month and eMonth >= 1 and eMonth <= 12 and eYear >= currentDay.year:
                    print("hello")
                else:
                    return redirect(url_for('payments'))




        return render_template('payments.html',
                                user=user,
                                movieName=movieName,
                                screening=screening,
                                adultTotal=adultTotal,
                                childTotal=childTotal,
                                seniorTotal=seniorTotal,
                                vipTotal=vipTotal,
                                priceTotal=priceTotal,
                                seatList = session['seatList'],
                                userEmailname=session['userEmail'],
                                cardDetails=cardDetails,
                                models=models,
                                newCardNumber=newCardNumber,
                                cardDetails2 = cardDetails2,
                                cardValue = session['card']
                                )

@app.route('/confirmation')
def confirm():
   # removes all session data
    wordlist = None
    movieID = None
    screeningID = None
    seatList = None
    userEmailname = None
    adultTotal = 0
    childTotal = 0
    seniorTotal = 0
    vipTotal = 0
    priceTotal = 0
    seatList = None
    cardDetails = None
    cardDetails2 = None
    newCardNumber = ""
    cardValue = None

    if 'movieVar' in session:
        movieID = session['movieVar']
        movieName = models.Movies.query.filter_by(id=movieID).first()
        screenings = models.Screenings.query.filter_by(movies_id = movieID).all()
    else:
        return redirect(url_for('home'))

    if 'scrnVar' in session:
        screeningID = session['scrnVar']
        screening = models.Screenings.query.filter_by(id=screeningID).first()
        seatsRes = models.Seat_Reserved.query.filter_by(screening=screeningID).all()
    else:
        return redirect(url_for('home'))

    if 'userEmail' in session:
        userEmailname = session['userEmail']
        user = models.Users.query.filter_by(email=userEmailname).first()
        cardDetails = models.CardDetails.query.filter_by(userID=user.id).all()
    else:
        userEmailname = "guest@cinema.com"
        user = models.Users.query.filter_by(email=userEmailname).first()
        cardDetails = models.CardDetails.query.filter_by(userID=user.id).all()

    if 'seatList' in session:
        seatList = session['seatList']
    else:
        return redirect(url_for('home'))

    if 'adult' in session:
        adultTotal = session['adult']
    else:
        return redirect(url_for('home'))

    if 'child' in session:
        childTotal = session['child']
    else:
        return redirect(url_for('home'))

    if 'senior' in session:
        seniorTotal = session['senior']
    else:
        return redirect(url_for('home'))

    if 'vip' in session:
        vipTotal = session['vip']
    else:
        return redirect(url_for('home'))

    if 'priceTotal' in session:
        priceTotal = session['priceTotal']
    else:
        return redirect(url_for('home'))

    if 'card' in session:
        cardValue = session['card']
    else:
        return redirect(url_for('home'))


    if seatList == None:
       print(wordlist)
    else:
        for item in seatList:
            wordlist = list(item)
            if len(wordlist) == 2:
               a = models.Seat_Reserved(screening=screeningID,
                                        rowReservedID=wordlist[0],
                                        seatNumberReservedID=wordlist[1])
            elif len(wordlist) == 3:
               a = models.Seat_Reserved(screening=screeningID,
                                        rowReservedID=wordlist[0],
                                        seatNumberReservedID=wordlist[1]+wordlist[2])
            db.session.add(a)
        db.session.commit()

    currentDay = datetime.datetime.now()
    employeeName = models.Employee.query.get(1)
    a = models.Receipts(userName=user.name,
                        employeeName=employeeName.name,
                        screening=screening.id,
                        price=priceTotal,
                        pricePaid=priceTotal,
                        change=0.00,
                        transactionTime=currentDay)
    db.session.add(a)
    db.session.commit()

    qr = qrcode.QRCode(
        version = 1,
        error_correction = qrcode.constants.ERROR_CORRECT_H,
        box_size = 10,
        border = 4,
    )
    receipt = models.Receipts.query.filter_by(userName=user.name, screening=screening.id, transactionTime=currentDay).first()

    data = receipt.id

    qr.add_data(data)
    qr.make(fit=True)

    img = qr.make_image()

    img.save("app/static/qrcodes/" + str(receipt.id) + ".png")

    print(userEmailname)
    msg = Message(recipients=[userEmailname],
                  sender=('MCUCinema','sc15fr@leeds.ac.uk'),
                  subject='MCUCinema Receipt'
                  )
    with app.open_resource("static/qrcodes/" + str(receipt.id) + ".png") as fp:
        msg.attach(str(receipt.id) + ".png", str(receipt.id) + "/png", fp.read())

    msg.body = render_template("emailTemp.txt", user=user,
                                          movieName=movieName,
                                          screening=screening,
                                          adultTotal=adultTotal,
                                          childTotal=childTotal,
                                          seniorTotal=seniorTotal,
                                          vipTotal=vipTotal,
                                          priceTotal=priceTotal,
                                          seatList = seatList,
                                          userEmailname=session['userEmail'],
                                          cardDetails=cardDetails,
                                          models=models,
                                          newCardNumber=newCardNumber,
                                          cardDetails2 = cardDetails2,
                                          cardValue = cardValue)

    msg.html = render_template("emailTemp.html", user=user,
                                          movieName=movieName,
                                          screening=screening,
                                          adultTotal=adultTotal,
                                          childTotal=childTotal,
                                          seniorTotal=seniorTotal,
                                          vipTotal=vipTotal,
                                          priceTotal=priceTotal,
                                          seatList = seatList,
                                          userEmailname=session['userEmail'],
                                          cardDetails=cardDetails,
                                          models=models,
                                          newCardNumber=newCardNumber,
                                          cardDetails2 = cardDetails2,
                                          cardValue = cardValue)

    mail = Mail(app)
    mail.send(msg)

    session.pop('movieSearch', None)
    session.pop('movieVar')
    session.pop('scrnVar')
    session.pop('adult')
    session.pop('child')
    session.pop('senior')
    session.pop('vip')
    session.pop('totalSeats')
    session.pop('priceTotal')
    session.pop('seatList')
    session.pop('card')

    return render_template('confirmation.html',
                            user=user,
                            movieName=movieName,
                            screening=screening,
                            adultTotal=adultTotal,
                            childTotal=childTotal,
                            seniorTotal=seniorTotal,
                            vipTotal=vipTotal,
                            priceTotal=priceTotal,
                            seatList = seatList,
                            userEmailname=session['userEmail'],
                            cardDetails=cardDetails,
                            models=models,
                            newCardNumber=newCardNumber,
                            cardDetails2 = cardDetails2,
                            cardValue = cardValue
                            )

# def email():
#     print(userEmailname.email)
#     msg = Message(recipients=[userEmailname.email],
#                   sender='xx@zz.yy',
#                   reply_to='aa@bb.cc',
#                   subject='MCUCinema Receipt'
#                   )
#     confirmation.html = mail.body
#     mail.send(msg)


@app.route('/logout')
def logout():
   # removes all session data
   session.clear()
   return redirect(url_for('home'))
