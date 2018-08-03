package com.konux.util;

import com.konux.model.Event;

public class TestObjectsUtil {
	public static Event createTestEvent() {
		Event event = new Event();
		event.setEvent("test");
		event.setUserId("123");
		event.setTimestamp(1533081600L);

		return event;
	}
}
