package com.konux.facade;

import com.konux.exception.RepositoryException;
import com.konux.model.Event;

/**
 * Facade used to convert and add the event to repository.
 *
 * @param  Event object from request
 * @throws RepositoryException when the event could not be added to repository
 */
public interface EventsFacade {
	public void addEvent(Event event) throws RepositoryException;
}
