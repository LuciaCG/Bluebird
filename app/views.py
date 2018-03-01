from app import app, models, db
from flask import render_template, url_for

@app.route('/', methods=['GET', 'POST'])
def index():
      movies = models.Movies.query.all()
      return render_template('table.html',
                                movies = movies)
