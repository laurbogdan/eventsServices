package com.konux.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.ResponseStatus;

import com.konux.exception.RepositoryException;
import com.konux.facade.EventsFacade;
import com.konux.model.Event;

/**
 * Controller used to register events and add them to repository.
 *
 * @param  Event object that will be added to repository
 * @throws RepositoryException when the event could not be added to repository
 */
@Controller
@RequestMapping("/events")
public class EventsController {

	@Autowired
	private EventsFacade eventsFacade;

	@PostMapping("/add")
	@ResponseStatus(HttpStatus.CREATED)
	public @ResponseBody void greeting(@RequestBody Event event) throws RepositoryException {
		eventsFacade.addEvent(event);
	}

}
