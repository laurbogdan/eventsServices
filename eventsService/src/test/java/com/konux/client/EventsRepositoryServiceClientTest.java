package com.konux.client;

import org.junit.Before;
import org.junit.Test;
import org.mockito.InjectMocks;
import org.mockito.MockitoAnnotations;

import com.konux.exception.RepositoryException;
import com.konux.model.protobuf.EventModel;

public class EventsRepositoryServiceClientTest {

	private static final String WRONG_HOST = "wrong_host";

	@InjectMocks
	private EventsRepositoryServiceClient eventsRepositoryServiceClientTest = new EventsRepositoryServiceClient();

	@Before
	public void setup() {
		MockitoAnnotations.initMocks(this);
	}

	@Test(expected = RepositoryException.class)
	public void shouldThrowExceptionForUnknownHost() throws RepositoryException {
		eventsRepositoryServiceClientTest.setHost(WRONG_HOST);
		eventsRepositoryServiceClientTest.addEvent(EventModel.Event.newBuilder().build());
	}

}
