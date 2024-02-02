// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MorbidMidwayMayhemV2 : ModuleRules
{
	public MorbidMidwayMayhemV2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}