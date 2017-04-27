#include "virtualmemorytest.h"

#include <stdlib.h>
#include <string.h>

#include <tari/input.h>
#include <tari/animation.h>
#include <tari/file.h>

#define TEXTURE_AMOUNT_BIG 11
#define TEXTURE_AMOUNT_MEDIUM 10
#define TEXTURE_AMOUNT_SMALL 100

#define TEXTURE_AMOUNT TEXTURE_AMOUNT_SMALL

static struct {
	TextureData mTexturesBig[TEXTURE_AMOUNT_BIG];
	TextureData mTexturesMedium[TEXTURE_AMOUNT_MEDIUM];
	TextureData mTexturesSmall[TEXTURE_AMOUNT_SMALL];
} gData;


static void loadVirtualMemoryTest() {
	Animation anim = createEmptyAnimation();
	anim.mFrameAmount = TEXTURE_AMOUNT_BIG;
	anim.mDuration = 1;	

	int i;
	for (i = 0; i < TEXTURE_AMOUNT_BIG; i++) {
		char path[1024];
		getPathWithNumberAffixedFromAssetPath(path, "assets/virtualmemory/BG_FRONT.pkg", i);
		gData.mTexturesBig[i] = loadTexture(path);
	}
	playAnimationLoop(makePosition(0,0,1), gData.mTexturesBig, anim, makeRectangleFromTexture(gData.mTexturesBig[0]));

	anim = createEmptyAnimation();
	anim.mFrameAmount = TEXTURE_AMOUNT_MEDIUM;
	anim.mDuration = 1;	

	for (i = 0; i < TEXTURE_AMOUNT_MEDIUM; i++) {
		char path[1024];
		strcpy(path, "assets/virtualmemory/MEDIUM.pkg");
		gData.mTexturesMedium[i] = loadTexture(path);
	}
	playAnimationLoop(makePosition(0,0,2), gData.mTexturesMedium, anim, makeRectangleFromTexture(gData.mTexturesMedium[0]));


	anim = createEmptyAnimation();
	anim.mFrameAmount = TEXTURE_AMOUNT_SMALL;
	anim.mDuration = 1;
	for (i = 0; i < (int)anim.mFrameAmount; i++) {
		char path[1024];
		strcpy(path, "assets/virtualmemory/SMALL.pkg");
		gData.mTexturesSmall[i] = loadTexture(path);
	}
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
