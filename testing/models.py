from testing import db
import datetime

class Moviles(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    
