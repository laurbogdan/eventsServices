package com.konux.exception;

/**
 * Exception used when the connection to the repository service is broken and the service is not able to add the event.
 */
public class RepositoryException extends Exception {

	private static final long serialVersionUID = 1L;

	public RepositoryException(String message) {
		super(message);
	}
}
