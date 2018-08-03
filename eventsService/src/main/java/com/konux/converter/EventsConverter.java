package com.konux.converter;

import org.springframework.stereotype.Component;

import com.konux.model.Event;
import com.konux.model.protobuf.EventModel;

/**
 * Converter used to convert the JSON object from request to the business model object used by lower components.
 *
 * @param  Event object from request
 * @return The new business model object
 */
@Component
public class EventsConverter {
	public EventModel.Event convert(Event event) {
		EventModel.Event protobufEvent = EventModel.Event.newBuilder().setEventDescription(event.getEvent())
				.setUserId(event.getUserId()).setTimestamp(event.getTimestamp()).build();
		return protobufEvent;
	}
}
