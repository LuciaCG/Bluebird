from app import db
import datetime
import hashlib


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
    Seat_Reserved = db.relationship('Seat_Reserved', backref='screenings', lazy='dynamic')
    userReciept = db.relationship('Receipts', backref='screenings', lazy='dynamic')

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
    row = db.Column(db.String(1), primary_key=True)
    seatNumber = db.Column(db.Integer, primary_key=True)

    # userReciept = db.relationship('Reciept', backref='screenings', lazy='dynamic')

    def __repr__(self):
        return '' % (self.row, self.seatNumber)


class Seat_Reserved(db.Model):
    screening = db.Column(db.Integer, db.ForeignKey('screenings.id'), primary_key=True)

    rowReservedID = db.Column(db.String(1), db.ForeignKey('seats.row'), primary_key=True)
    seatNumberReservedID = db.Column(db.Integer, db.ForeignKey('seats.seatNumber'), primary_key=True)

    rowReserved = db.relationship("Seats", foreign_keys=[rowReservedID])
    seatNumberReserved = db.relationship("Seats", foreign_keys=[seatNumberReservedID])


    def __repr__(self):
        return '' % (self.screening, self.rowReservedID, self.seatNumberReservedID)

class Employee(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(20))
    password = db.Column(db.String(50))
    reciept = db.relationship('Receipts', backref='employee', lazy='dynamic')

    def __init__(self, name, password):
        self.name = name
        a = hashlib.sha256()
        a.update(password.encode('utf-8'))
        self.password = a.hexdigest()

    def __repr__(self):
        return '' % (self.id, self.name, self.password)


class Users(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    email = db.Column(db.String(20))
    name = db.Column(db.String(20))
    password = db.Column(db.String(50))
    reciept = db.relationship('Receipts', backref='users', lazy='dynamic')
    cardDetails = db.relationship('CardDetails', backref='users', lazy='dynamic')

    def __init__(self, password, name, email):
        self.name = name
        a = hashlib.sha256()
        a.update(password.encode('utf-8'))
        self.password = a.hexdigest()
        self.email = email

    def __repr__(self):
        return '' % (self.id, self.name, self.password, self.email)


class TypeOfTickets(db.Model):
    ticketType = db.Column(db.String(25), primary_key=True)
    price = db.Column(db.Float)

    def __repr__(self):
        return '' % (self.ticketType, self.price)


class Receipts(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    userName = db.Column(db.String(20), db.ForeignKey('users.id'))
    employeeName = db.Column(db.String(20), db.ForeignKey('employee.id'))
    screening = db.Column(db.Integer, db.ForeignKey('screenings.id'))
    price = db.Column(db.Float)
    pricePaid = db.Column(db.Float)
    change = db.Column(db.Float)
    transactionTime = db.Column(db.DateTime)

    def __repr__(self):
        return '' % (self.id, self.userName, self.employeeName, self.screening, self.price, self.pricePaid, self.change, self.transactionTime)


class CardDetails(db.Model):
    userID = db.Column(db.Integer, db.ForeignKey('users.id'), primary_key=True)
    cardNumber = db.Column(db.String(16), primary_key=True)
    exMonth = db.Column(db.String(2))
    exYear = db.Column(db.String(4))
    securityNumber = db.Column(db.String(3))

    def __repr__(self):
        return '' % (self.userID, self.cardNumber, self.exMonth, self.exYear, self.securityNumber)

    # def __init__(self, userID, cardNumber, exMonth, exYear, securityNumber):
    #     self.userID = userID
    #     a = hashlib.sha256()
    #     a.update(cardNumber.encode('utf-8'))
    #     self.cardNumber = a.hexdigest()
    #     self.exMonth = exMonth
    #     self.exYear = exYear
    #     self.securityNumber = securityNumber
