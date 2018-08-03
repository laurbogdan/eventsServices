package com.konux.service.impl;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.konux.client.EventsRepositoryServiceClient;
import com.konux.exception.RepositoryException;
import com.konux.model.protobuf.EventModel.Event;
import com.konux.service.EventsService;

/**
 * Implementation of {@link EventsService}.
 *
 * @param  Event object
 * @throws RepositoryException when the event could not be added to repository.
 */
@Service
public class EventsServiceImpl implements EventsService {

	@Autowired
	private EventsRepositoryServiceClient client;

	@Override
	public void addEvent(Event event) throws RepositoryException {
		client.addEvent(event);
	}

}
