from testing import testing
from flask import render_template, url_for

@testing.route('/')
def index():
      return render_template('/table.html')
