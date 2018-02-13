from flask import Flask
from flask_sqlalchemy import SQLAlchemy

testing = Flask(__name__)
testing.config.from_object('config')
db = SQLAlchemy(testing)

from testing import models
