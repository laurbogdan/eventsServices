package com.konux.facade.impl;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.konux.converter.EventsConverter;
import com.konux.exception.RepositoryException;
import com.konux.facade.EventsFacade;
import com.konux.model.Event;
import com.konux.model.protobuf.EventModel;
import com.konux.service.EventsService;

/**
 * Implementantion of {@link EventsFacade}.
 *
 * @param  Event object from request
 * @throws RepositoryException when the event could not be added to repository
 */
@Component
public class EventsFacadeImpl implements EventsFacade {

	@Autowired
	private EventsService eventsService;

	@Autowired
	private EventsConverter eventsConverter;

	@Override
	public void addEvent(Event event) throws RepositoryException {
		EventModel.Event protobufEvent = eventsConverter.convert(event);
		eventsService.addEvent(protobufEvent);
	}

}
