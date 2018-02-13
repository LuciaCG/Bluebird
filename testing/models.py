from testing import db
import datetime

class Moviles(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    movieTitle = db.Column(db.String(150))
    synopsis = db.Column(db.String(1000))
    rating = db.Column(db.Float)
