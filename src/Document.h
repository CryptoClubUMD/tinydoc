#ifndef DOCUMENT_
#define DOCUMENT_

#include <string>
#include <vector>
#include <memory>

#include "Commit.h"

enum commit_type_t {INS, DEL};

class Document {
private:
	// Only load the last N commits into the history.
	// This is to save RAM and not load ALL history.
	static const unsigned int cached_commit_history = 20;

	bool initialized = false;

	// Local document location
	std::string document_location;

	// The head commit is the timeline hash where the document is in it's most final form
	std::shared_ptr<Commit> head_commit;

	// Determines whether the last cached version of this file is in line with the last known commit
	bool cachedIsLastCommit() const;

	// Commit count
	unsigned int commit_count;

	// Document track ID
	unsigned int tracked_id;

	// Document tracked status
	bool is_tracked;

	// Creates the cache file at latest commit in the 'oldcache' directory.
	// Name of the file is "old_[latest commit full hash]_[document name].[document_extension]"
	void cacheDoc() const;
	
	void loadDocumentMeta() const;

	// Gets the filename of the file using the URL
	std::string filename() const;

public:
	Document();

	Document(std::string rdocument_location);
	
	Document(unsigned int rtracked_id);

	// Rollback the commit history to a certain point in the timeline.
	void rollback(std::string timeline_hash);

	// Build document up to latest commit
	void bringup();

	// Initialize the document for tracking
	void initialize();

	// Gets document hash at the head commit
	std::string getHeadHash() const;

	// Save document tracking metadata
	void saveDocMeta() const;

	// Getter: document_location
	std::string getDocumentLocation() const;

	// Getter: head_commit
	std::shared_ptr<Commit> getHeadCommit() const;

	// Sets the head commit
	void setHeadCommit(std::shared_ptr<Commit> new_head);

	// Find differences and add them as commits
	void scanDiff();

	// Creates a new commit for a given line.
	std::shared_ptr<Commit> commitLine(unsigned int line_num, commit_type_t commit_type);
};

#endif
