from flask import Flask
from flask_sqlalchemy import SQLAlchemy

testing = Flask(__name__)
testing.config.from_object('config')
db = SQLAlchemy(testing)

testing.static_folder = 'static'

from testing import models
from app import views
