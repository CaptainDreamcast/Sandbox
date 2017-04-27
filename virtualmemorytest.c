#include "virtualmemorytest.h"

#include <stdlib.h>

#include <tari/input.h>
#include <tari/animation.h>
#include <tari/file.h>

static struct {
	TextureData mTextures[10];

} gData;

static void loadVirtualMemoryTest() {
	Animation anim = createEmptyAnimation();
	anim.mFrameAmount = 11;
	anim.mDuration = 20;

	int i;
	for (i = 0; i < (int)anim.mFrameAmount; i++) {
		char path[1024];
		getPathWithNumberAffixedFromAssetPath(path, "assets/virtualmemory/BG_FRONT.pkg", i);
		gData.mTextures[i] = loadTexture(path);
	}

	playAnimationLoop(makePosition(0,0,1), gData.mTextures, anim, makeRectangleFromTexture(gData.mTextures[0]));
}

static void unloadVirtualMemoryTest() {

}

static void updateVirtualMemoryTest() {

}

static void drawVirtualMemoryTest() {

}

static Screen* getNextVirtualMemoryTestScreen() {
	if (hasPressedAbortFlank()) {
		abortScreenHandling();
	}

	return NULL;
}

Screen VirtualMemoryTest = {
	.mLoad = loadVirtualMemoryTest,
	.mUnload = unloadVirtualMemoryTest,
	.mUpdate = updateVirtualMemoryTest,
	.mDraw = drawVirtualMemoryTest,
	.mGetNextScreen = getNextVirtualMemoryTestScreen
};
