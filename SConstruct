env = Environment()

# System level constants
PROGRAM_NAME = 'htop'

# Specify the include directory for headers
env.Append(CPPPATH=['./header'])

# Include the SConscript file from the src directory
src_env = env.Clone()
SConscript('./src/SConscript', exports='src_env')

# Include Libs
env.Append(LIBPATH=['./src'])

# Build the main program with the log library
env.Program(target=PROGRAM_NAME, source='main.cpp', LIBS=['src_obj'])
