package com.konux.integration;

import static org.mockito.ArgumentMatchers.any;
import static org.mockito.Mockito.doNothing;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.post;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.http.MediaType;
import org.springframework.test.context.junit4.SpringRunner;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.web.servlet.config.annotation.EnableWebMvc;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.konux.client.EventsRepositoryServiceClient;
import com.konux.model.Event;
import com.konux.model.protobuf.EventModel;
import com.konux.util.TestObjectsUtil;

@RunWith(SpringRunner.class)
@SpringBootTest(classes = ApplicationConfig.class)
@EnableWebMvc
@AutoConfigureMockMvc
public class EventsServiceIT {

	@Autowired
	EventsRepositoryServiceClient eventsRepositoryServiceClient;

	@Autowired
	private MockMvc mvc;

	@Test
	public void shouldReturnCreatedStatusWhenEventHasBeenCreated() throws Exception {

		doNothing().when(eventsRepositoryServiceClient).addEvent(any(EventModel.Event.class));
		ObjectMapper mapper = new ObjectMapper();
		Event event = TestObjectsUtil.createTestEvent();
		String json = mapper.writeValueAsString(event);
		mvc.perform(post("/events/add").content(json).contentType(MediaType.APPLICATION_JSON))
				.andExpect(status().isCreated());
	}

	@Test
	public void shouldReturnBadRequestForBadJsonPropertiesNames() throws Exception {
		doNothing().when(eventsRepositoryServiceClient).addEvent(any(EventModel.Event.class));
		mvc.perform(post("/events/add").content("\"eventDescription\":\"description\"")
				.contentType(MediaType.APPLICATION_JSON)).andExpect(status().isBadRequest());
	}
}
