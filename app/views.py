from app import app, models, db
from datetime import timedelta
from flask import render_template, url_for, request, session, redirect, flash
from .forms import LoginForm, RegistrationForm, SessionForm, AddCardForm
from datetime import datetime
import hashlib

# @app.before_request
# def make_session_permanent():
#     session.permanent = True
#     app.permanent_session_lifetime = timedelta(seconds=20)




@app.route('/home', methods=['GET', 'POST'])
def home():
    userEmailname = None
    if 'userEmail' in session:
        userEmailname = session['userEmail']
    else:
        session['userEmail'] = 'Guest User'


    return render_template('home.html',
                            userEmailname=session['userEmail'])

@app.route('/login', methods=['GET', 'POST'])
def login():
    now = datetime.now()
    form = LoginForm()
    form2 = SessionForm()

    if form.validate_on_submit():
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
            p = models.CardDetails(userID=user.id,
                            cardNumber=form.cardNumber.data,
                            exMonth=form.exMonth.data,
                            exYear=form.exYear.data
                            )
            db.session.add(p)
            db.session.commit()
            return redirect(url_for('userPage'))
    else:
        session['userEmail'] = 'Guest User'
    return render_template('userpage.html',
                            userEmailname=session['userEmail'],
                            user=user,
                            form=form
                            )

@app.route('/nowshowing', methods=['GET', 'POST'])
def viewmovies():
        movies = models.Movies.query.all()
        movieOne = models.Movies.query.get(1)
        movieTwo = models.Movies.query.get(2)
        movieThree = models.Movies.query.get(3)

        movieID = None

        userEmailname = None
        if 'userEmail' in session:
            userEmailname = session['userEmail']
        else:
            session['userEmail'] = 'Guest User'

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
                                userEmailname=session['userEmail']
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
            session['userEmail'] = 'Guest User'

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
            session['userEmail'] = 'Guest User'

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
                        print(totalSeats)
                        print(seatList)
                else:
                    if seatID in seatList:
                        seatList.remove(seatID)
                        totalSeats += 1
                        session['seatList'] = seatList
                        session['totalSeats'] = totalSeats
                        print(totalSeats)
                        print(seatList)

                    else:
                        if totalSeats > 0:
                            seatList.append(seatID)
                            totalSeats -= 1
                            session['seatList'] = seatList
                            session['totalSeats'] = totalSeats
                            print(totalSeats)
                            print(seatList)

                wordlist = list(seatID)
                if wordlist == None:
                    print(wordlist)
                else:
                    if len(wordlist) == 2:
                        a = models.Seat_Reserved(screening=screeningID, rowReservedID=wordlist[0] , seatNumberReservedID=wordlist[1])
                    elif len(wordlist) == 3:
                        a = models.Seat_Reserved(screening=screeningID, rowReservedID=wordlist[0] , seatNumberReservedID=wordlist[1]+wordlist[2])
                    # db.session.add(a)
                    # db.session.commit()

                priceTotal = adultTotal+childTotal+seniorTotal+vipTotal

                return redirect(url_for('booktickets'))

                priceTotal = adultTotal+childTotal+seniorTotal+vipTotal

            elif 'gotoPay' in request.form:
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
        userEmailname = None
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

        if 'userEmail' in session:
            userEmailname = session['userEmail']
            user = models.Users.query.filter_by(email=userEmailname).first()

        if 'movieVar' in session:
            movieID = session['movieVar']
            movieName = models.Movies.query.filter_by(id=movieID).first()
            screenings = models.Screenings.query.filter_by(movies_id = movieID).all()

        if 'scrnVar' in session:
            screeningID = session['scrnVar']
            screening = models.Screenings.query.filter_by(id=screeningID).first()
            seatsRes = models.Seat_Reserved.query.filter_by(screening=screeningID).all()

        if 'adult' in session:
            adultTotal = session['adult']

        if 'child' in session:
            childTotal = session['child']

        if 'senior' in session:
            seniorTotal = session['senior']

        if 'vip' in session:
            vipTotal = session['vip']

        if 'priceTotal' in session:
            priceTotal = session['priceTotal']




        if 'userEmail' in session:
            userEmailname = session['userEmail']
        else:
            session['userEmail'] = 'Guest User'

        if request.method == 'POST':
            screeningID = request.form.get('bookSeat')

        session['scrnVar'] = screeningID






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
                                cardDetails=cardDetails
                                )

@app.route('/logout')
def logout():
   # removes all session data
   session.clear()
   return render_template('home.html')
