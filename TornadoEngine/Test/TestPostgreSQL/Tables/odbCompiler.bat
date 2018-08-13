set PATH=%DEP_PATH_MMO_FRAMEWORK%\Include\ODB\odb-2.4.0-i686-windows\bin

odb --std c++11 --database pgsql --generate-prepared --generate-query --schema public --schema-format embedded --generate-schema -o "Generated files" *.hxx