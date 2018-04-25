from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_mail import Mail

app = Flask(__name__)
mail = Mail(app)
app.config.from_object('config')
db = SQLAlchemy(app)

app.static_folder = 'static'

app.secret_key = 'anything'

from app import views, models
