db:
	python3 db_create.py

pop:
	python3 populatingDatabase.py

mig:
	python3 db_migrate.py

freshAll:
	make clean
	python3 db_create.py
	python3 populatingDatabase.py

oldAll:
	python3 db_migrate.py
	python3 populatingDatabase.py

clean:
	rm -rf app.db
	rm -r __pycache__
	rm -r db_repository
	rm -r app/__pycache__
