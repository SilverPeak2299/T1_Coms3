
int base_red {57};
int base_green {212};
int base_blue {98};

int highlight_red {240};
int highlight_green {12};
int highlight_blue {54};



LinkedList<int> marble_list = LinkedList<int>();

unsigned long int last_time;

void led_init () {
  pixels.begin();
  for (int i=0; i < led_count; i++) {
    pixels.setPixelColor(i, pixels.Color(base_red, base_blue, base_red));
  }

  pixels.show();
  last_time = millis();
}

void led_add_marble () {
  marble_list.add(0);
}

void led_remove_marble (int x) {
  marble_list.remove(x);
}

void led_remove_marble () {
  marble_list.remove(0);
}

void led_update () {
  if (millis() - last_time < (avg_time / led_count)) { return; } // sets the time interval for updating the leds

  int list_size =  marble_list.size();

  for (int i=0; i < led_count; i++) {
    pixels.setPixelColor(i, pixels.Color(base_red, base_blue, base_red));
  }

  for (int i = 0; i < list_size; i++) {
    pixels.setPixelColor(marble_list.get(i), pixels.Color(highlight_red, highlight_green, highlight_blue));
      marble_list.set(i, marble_list.get(i) + 1);

      if (marble_list.get(i) >= led_count) { led_remove_marble(i); }  
  }

  last_time = millis();
}

