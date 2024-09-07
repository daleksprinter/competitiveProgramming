package main

import "testing"

func TestSample(t *testing.T) {
	got := 1
	want := 1
	if got != want {
		t.Errorf("%d is not %d", got, want)
	}
}

var cntpoptests = []struct {
	index int
	last  int64
	want  int64
}{
	{1, 1, 1},
	{1, 2, 1},
	{1, 3, 2},
	{1, 4, 2},
	{2, 1, 0},
	{2, 2, 1},
	{2, 3, 2},
	{2, 4, 2},
	{3, 1, 0},
	{3, 2, 0},
	{3, 3, 0},
	{3, 4, 1},
	{1, 1152921504606846975, 576460752303423488},
}

func TestCntPop(t *testing.T) {
	for _, tt := range cntpoptests {
		got := cntpops(tt.index, tt.last)
		if got != tt.want {
			t.Errorf("cntpops(%d, %d) = %d; want %d", tt.index, tt.last, got, tt.want)
		}
	}
}
