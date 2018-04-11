db:
	python db_create.py

pop:
	python populatingDatabase.py

mig:
	python db_migrate.py

freshAll:
	rm -rf app.db
	rm -r __pycache__
	rm -r db_repository
	rm -r app/__pycache__
	python db_create.py
	python populatingDatabase.py

oldAll:
	python db_migrate.py
	python populatingDatabase.py

clean:
	rm -rf app.db
	rm -r __pycache__
	rm -r db_repository
	rm -r app/__pycache__
