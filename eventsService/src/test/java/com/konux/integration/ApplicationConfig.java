package com.konux.integration;

import org.mockito.Mockito;
import org.springframework.context.annotation.Bean;

import com.konux.client.EventsRepositoryServiceClient;
import com.konux.controller.EventsController;
import com.konux.converter.EventsConverter;
import com.konux.facade.EventsFacade;
import com.konux.facade.impl.EventsFacadeImpl;
import com.konux.service.EventsService;
import com.konux.service.impl.EventsServiceImpl;

public class ApplicationConfig {

	@Bean
	public EventsRepositoryServiceClient eventsRepositoryServiceClient() {
		return Mockito.mock(EventsRepositoryServiceClient.class);
	}

	@Bean
	public EventsController eventsController() {
		return new EventsController();
	}

	@Bean
	public EventsConverter eventsConverter() {
		return new EventsConverter();
	}

	@Bean
	public EventsFacade eventsFacade() {
		return new EventsFacadeImpl();
	}

	@Bean
	public EventsService eventsService() {
		return new EventsServiceImpl();
	}
}
