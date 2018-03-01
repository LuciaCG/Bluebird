import os
if (not os.path.isfile('app.db')):
    import db_create
    import db_migrate
    import populatingDatabase

from app import app
app.run(debug=True)
