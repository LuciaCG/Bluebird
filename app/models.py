from app import db
import datetime

class Movies(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    movieTitle = db.Column(db.String(150))
    synopsis = db.Column(db.String(1000))
    rating = db.Column(db.Float)
    screening = db.relationship('Screenings', backref='movies', lazy='dynamic')

    def __repr__(self):
        return '' % (self.id, self.movieTitle, self.synopsis, self.rating)


class Screenings(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    movies_id = db.Column(db.Integer, db.ForeignKey('movies.id'))
    screen_id = db.Column(db.Integer, db.ForeignKey('screen.id'))
    time = db.Column(db.DateTime)
    # seatReserved = db.relationship('SeatReserved', backref='screenings', lazy='dynamic')
    # userReciept = db.relationship('Reciept', backref='screenings', lazy='dynamic')

    def __repr__(self):
        return '' % (self.id, self.movies_id, self.time)


class Screen(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    screenName = db.Column(db.String(150))
    Capacity = (db.Column(db.Integer))
    screening = db.relationship('Screenings', backref='screen', lazy='dynamic')


    def __repr__(self):
        return '' % (self.id, self.Capacity, self.screenName)

class Seats(db.Model):
    row = db.Column(db.String(1), primary_key=True)
    seatNumber = db.Column(db.Integer, primary_key=True)
    # seatReserved = db.relationship('SeatReserved', backref='screenings', lazy='dynamic')
    # userReciept = db.relationship('Reciept', backref='screenings', lazy='dynamic')

    def __repr__(self):
        return '' % (self.row, self.seatNumber)
