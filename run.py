import os
if (not os.path.isfile('app.db')):
    import db_create
    import db_migrate
    import populatingDatabase

# import db_migrate



from app import app
app.run(debug=True)
