project(DocSyncClient)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")

add_executable(
	DocSyncClient
	main.cpp
	Document.cpp
	Commit.cpp
	CSVConfig.cpp
	jsoncpp.cpp
	tests.cpp
)
