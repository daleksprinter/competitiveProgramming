package main

import "testing"

func TestSample(t *testing.T) {
	got := 1
	want := 1
	if got != want {
		t.Errorf("%d is not %d", got, want)
	}
}

var sample = []struct {
	In  int
	Out int
}{
	{1, 1},
}

func TestData(t *testing.T) {
	for _, tt := range sample {
		got := tt.In
		if got != tt.Out {
			t.Errorf("%d is not %d", got, tt.Out)
		}
	}
}
