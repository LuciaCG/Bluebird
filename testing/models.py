from testing import db
import datetime

class Movies(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    movieTitle = db.Column(db.String(150))
    synopsis = db.Column(db.String(1000))
    rating = db.Column(db.Float)

    def __repr__(self):
        return '' % (self.id, self.movieTitle, self.synopsis, self.rating)
