from app import app, models, db
from flask import render_template, url_for

@app.route('/', methods=['GET', 'POST'])
def home():
      return render_template('home.html')


@app.route('/nowshowing', methods=['GET', 'POST'])
def viewmovies():
      movies = models.Movies.query.all()
      movieOne = models.Movies.query.get(1)
      movieTwo = models.Movies.query.get(2)
      movieThree = models.Movies.query.get(3)


      return render_template('nowshowing.html',
                                movies = movies,
                                movieOne = movieOne,
                                movieTwo = movieTwo,
                                movieThree = movieThree
                                )


@app.route('/showtimes', methods=['GET', 'POST'])
def showtimes():

      return render_template('showtimes.html')
