from app import app, models, db
from flask import render_template, url_for

@app.route('/', methods=['GET', 'POST'])
def home():
      return render_template('home.html')


@app.route('/viewmovies', methods=['GET', 'POST'])
def viewmovies():
      movies = models.Movies.query.all()
      movieOne = models.Movies.query.get(1)
      movieTwo = models.Movies.query.get(2)
      movieThree = models.Movies.query.get(3)


      return render_template('viewmovies.html',
                                movies = movies,
                                movieOne = movieOne,
                                movieTwo = movieTwo,
                                movieThree = movieThree
                                )
