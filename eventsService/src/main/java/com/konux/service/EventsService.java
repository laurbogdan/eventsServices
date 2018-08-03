package com.konux.service;

import com.konux.exception.RepositoryException;
import com.konux.model.protobuf.EventModel.Event;

/**
 * Service used to add the event to repository.
 *
 * @param  Event object
 * @throws RepositoryException when the event could not be added to repository
 */
public interface EventsService {
	public void addEvent(Event event) throws RepositoryException;
}
