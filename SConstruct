env = Environment()
env.Decider('content-timestamp')

# System level constants
PROGRAM_NAME = 'htop'

# Specify the include directory for headers
env.Append(CPPPATH=['./header', './model'])

# Include the SConscript file from the src directory
src_env = env.Clone()
SConscript('./src/SConscript', exports='src_env')

# Include version and static library
env.Append(CXXFLAGS=['-std=c++17'])
env.Append(LIBPATH=['./src'])

# Build the main program with the log library
env.Program(target=PROGRAM_NAME, source='main.cpp', LIBS=['src_obj'])
