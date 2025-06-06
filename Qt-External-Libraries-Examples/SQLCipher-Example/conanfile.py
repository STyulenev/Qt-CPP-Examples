from conan import ConanFile

class MyConanSettings(ConanFile):
   settings = "os", "compiler", "build_type", "arch"
   generators = "CMakeDeps"

   def requirements(self):
       self.requires("sqlite3/3.47.0")
       self.requires("sqlite3mc/2.1.0")


   def configure(self):
       self.options["sqlite3mc/*"].enable_column_metadata=False