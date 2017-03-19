#include <iostream>
#include <string>

#include "Document.h"
#include "CSVConfig.h"

Document::Document(std::string rdocument_location){
	document_location = rdocument_location;
}

void Document::initialize(){
	// If: document already tracked
		// Fill in document variables from file
		// Make sure cached correctly
		// Load commits for that file
	// Else:
		// Create an add commit for each line already existing
		// Cache the document in the compare folder
		// Add the document to the tracked list
	initialized = true;
}

bool Document::documentIsTracked() const{
	CSVConfig tracked_docs = CSVConfig("../data/tracked_docs.csv");
	bool is_tracked(false);

	if(!document_location.empty()){
		for(unsigned int i = 0; i < tracked_docs.rowCount(); ++i){
			if(document_location == tracked_docs.getValue(i, 0)){
				is_tracked = true;
			}
		}
	}

	return is_tracked;
}

bool Document::cachedIsLastCommit() const{
	return false;
}

void Document::cacheDoc() const{
	if(!cachedIsLastCommit()){

	}
}

void Document::rollback(std::string timeline_hash){

}

void Document::bringup(){

}

std::string Document::getHeadHash() const{
	std::string head_hash = "DOC_HASH_AT_HEAD";
	return head_hash;
}

std::string Document::getDocumentLocation() const{
	return document_location;
}

std::shared_ptr<Commit> Document::getHeadCommit() const{
	return head_commit;
}

void Document::setHeadCommit(std::shared_ptr<Commit> new_head){
	head_commit = new_head;
}

void Document::scanDiff(){

}
