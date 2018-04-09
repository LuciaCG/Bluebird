from app import app, models, db
from flask import render_template, url_for, request, session, redirect

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

        session['variable'] = movieID

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

        if 'variable' in session:
            movieID = session['variable']
            movieName = models.Movies.query.filter_by(id=movieID).first()
            screenings = models.Screenings.query.filter_by(movies_id = movieID).all()


        else:
            # movieName = models.Movies.query.filter_by(id=1).first()
            return redirect(url_for('home'))


        if request.method == 'POST':
            screeningID = request.form.get('bookSeat')
            # return redirect(url_for('showtimes'))

        session['scrnVar'] = screeningID


        return render_template('showtimes.html',
                                movieName = movieName,
                                screenings = screenings
                                )
