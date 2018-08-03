package com.konux.application;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

/**
 * Class used to load the spring boot application.
 */
@SpringBootApplication(scanBasePackages = "com.konux")
public class EventsServiceApplication {
	public static void main(String[] args) {
		SpringApplication.run(EventsServiceApplication.class, args);
	}
}
