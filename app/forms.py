from flask_wtf import Form
from wtforms import (BooleanField, StringField, PasswordField, IntegerField,
                     validators)
from wtforms.validators import DataRequired, Length, InputRequired, Email

class LoginForm(Form):
    name = StringField('name', validators=[DataRequired()])
    password = PasswordField('password', validators=[DataRequired()])
    remember_me = BooleanField('remember_me', default=False)

class RegistrationForm(Form):
    name = StringField('name', [validators.Required(),
        validators.Length(min = 1, max = 40)])
    email = StringField('email', [validators.Required(),
        validators.Length(min = 1, max = 40)])
    password = PasswordField('New Password', [validators.Required(),
        validators.Length(min=1, max=16)])
    confirm = PasswordField('Repeat Password', [validators.Required(),
        validators.EqualTo('password', message='Passwords must match')])

class SessionForm(Form):
    value = StringField('value', validators=[DataRequired()])
