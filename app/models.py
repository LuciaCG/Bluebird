from app import db
import datetime

class Movies(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    movieTitle = db.Column(db.String(150))
    synopsis = db.Column(db.String(1000))
    ageRating = db.Column(db.String(3))
    screening = db.relationship('Screenings', backref='movies', lazy='dynamic')

    def __repr__(self):
        return '' % (self.id, self.movieTitle, self.synopsis, self.ageRating)


class Screenings(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    movies_id = db.Column(db.Integer, db.ForeignKey('movies.id'))
    screen_id = db.Column(db.String(150), db.ForeignKey('screen.screenName'))
    time = db.Column(db.DateTime)
    seatReserved = db.relationship('Seat_Reserved', backref='screenings', lazy='dynamic')
    # userReciept = db.relationship('Reciept', backref='screenings', lazy='dynamic')

    def __repr__(self):
        return '' % (self.id, self.movies_id, self.screen_id, self.time)


class Screen(db.Model):
    # id = db.Column(db.Integer, primary_key=True)
    screenName = db.Column(db.String(150), primary_key=True)
    Capacity = (db.Column(db.Integer))
    screening = db.relationship('Screenings', backref='screen', lazy='dynamic')

    def __repr__(self):
        return '' % (self.screenName, self.Capacity)

class Seats(db.Model):
    rowSeatNumber = db.Column(db.String(3), primary_key=True)
    seatReserved = db.relationship('Seat_Reserved', backref='seats', lazy='dynamic')
    # userReciept = db.relationship('Reciept', backref='screenings', lazy='dynamic')

    def __repr__(self):
        return '' % (self.rowSeatNumber)


class Seat_Reserved(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    screening = db.Column(db.Integer, db.ForeignKey('screenings.id'))
    seatRow = db.Column(db.String(3), db.ForeignKey('seats.rowSeatNumber'))

    def __repr__(self):
        return '' % (self.rowSeatNumber)

class Employee(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(20))
    password = db.Column(db.String(50))
    #referenceReceipt

    def __repr__(self):
        return '' % (self.id, self.name, self.password)


class Users(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    email = db.Column(db.String(20))
    name = db.Column(db.String(20))
    password = db.Column(db.String(50))
    #referenceReceipt

    def __repr__(self):
        return '' % (self.id, self.name, self.password)
