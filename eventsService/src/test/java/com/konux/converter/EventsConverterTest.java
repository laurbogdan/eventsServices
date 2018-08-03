package com.konux.converter;

import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;
import org.mockito.InjectMocks;
import org.mockito.MockitoAnnotations;

import com.konux.exception.RepositoryException;
import com.konux.model.Event;
import com.konux.model.protobuf.EventModel;
import com.konux.util.TestObjectsUtil;

public class EventsConverterTest {

	@InjectMocks
	private EventsConverter eventsConverter = new EventsConverter();

	@Before
	public void setup() {
		MockitoAnnotations.initMocks(this);
	}

	@Test
	public void shouldPopulateAllTheFieldsForTheNewObject() throws RepositoryException {
		Event event = TestObjectsUtil.createTestEvent();
		EventModel.Event protoBufEvent = eventsConverter.convert(event);
		assertEquals(event.getEvent(), protoBufEvent.getEventDescription());
		assertEquals(event.getTimestamp(), protoBufEvent.getTimestamp());
		assertEquals(event.getUserId(), protoBufEvent.getUserId());
	}

}
