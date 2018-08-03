package com.konux.client;

import java.net.Socket;
import java.net.UnknownHostException;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

import com.konux.exception.RepositoryException;
import com.konux.model.protobuf.EventModel.Event;

/**
 * Client used to communicate with the C++ repository service. It opens a socket and sends the protobuf object to the
 * C++ service using TCP/IP.
 *
 * @param  Event object
 * @throws RepositoryException when the event could not be added to repository
 */
@Component
public class EventsRepositoryServiceClient {

	private static final Logger LOG = LoggerFactory.getLogger(EventsRepositoryServiceClient.class);

	@Value("${repositoryClient.host}")
	private String host;
	@Value("${repositoryClient.port}")
	private int port;

	public void addEvent(Event event) throws RepositoryException {
		try {
			Socket client = new Socket(host, port);
			event.writeTo(client.getOutputStream());
			client.close();
		} catch (UnknownHostException e) {
			LOG.error("UnknownHostException", e);
			throw new RepositoryException("Something went wrong. Could not add the event to repository.");
		} catch (Exception e) {
			LOG.error("Could not establish connection with the repository.", e);
			throw new RepositoryException("Something went wrong. Could not add the event to repository.");
		}
	}
}
