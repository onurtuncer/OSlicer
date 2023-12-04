#pragma once

#include <ostream>

namespace OSlicer
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	enum class KeyState
	{
		None = -1,
		Pressed,
		Held,
		Released
	};

	enum class CursorMode
	{
		Normal = 0,
		Hidden = 1,
		Locked = 2
	};

	typedef enum class MouseButton : uint16_t
	{
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Left = Button0,
		Right = Button1,
		Middle = Button2
	} Button;


	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, MouseButton button)
	{
		os << static_cast<int32_t>(button);
		return os;
	}
}

// From glfw3.h
#define OS_KEY_SPACE           ::OSlicer::Key::Space
#define OS_KEY_APOSTROPHE      ::OSlicer::Key::Apostrophe    /* ' */
#define OS_KEY_COMMA           ::OSlicer::Key::Comma         /* , */
#define OS_KEY_MINUS           ::OSlicer::Key::Minus         /* - */
#define OS_KEY_PERIOD          ::OSlicer::Key::Period        /* . */
#define OS_KEY_SLASH           ::OSlicer::Key::Slash         /* / */
#define OS_KEY_0               ::OSlicer::Key::D0
#define OS_KEY_1               ::OSlicer::Key::D1
#define OS_KEY_2               ::OSlicer::Key::D2
#define OS_KEY_3               ::OSlicer::Key::D3
#define OS_KEY_4               ::OSlicer::Key::D4
#define OS_KEY_5               ::OSlicer::Key::D5
#define OS_KEY_6               ::OSlicer::Key::D6
#define OS_KEY_7               ::OSlicer::Key::D7
#define OS_KEY_8               ::OSlicer::Key::D8
#define OS_KEY_9               ::OSlicer::Key::D9
#define OS_KEY_SEMICOLON       ::OSlicer::Key::Semicolon     /* ; */
#define OS_KEY_EQUAL           ::OSlicer::Key::Equal         /* = */
#define OS_KEY_A               ::OSlicer::Key::A
#define OS_KEY_B               ::OSlicer::Key::B
#define OS_KEY_C               ::OSlicer::Key::C
#define OS_KEY_D               ::OSlicer::Key::D
#define OS_KEY_E               ::OSlicer::Key::E
#define OS_KEY_F               ::OSlicer::Key::F
#define OS_KEY_G               ::OSlicer::Key::G
#define OS_KEY_H               ::OSlicer::Key::H
#define OS_KEY_I               ::OSlicer::Key::I
#define OS_KEY_J               ::OSlicer::Key::J
#define OS_KEY_K               ::OSlicer::Key::K
#define OS_KEY_L               ::OSlicer::Key::L
#define OS_KEY_M               ::OSlicer::Key::M
#define OS_KEY_N               ::OSlicer::Key::N
#define OS_KEY_O               ::OSlicer::Key::O
#define OS_KEY_P               ::OSlicer::Key::P
#define OS_KEY_Q               ::OSlicer::Key::Q
#define OS_KEY_R               ::OSlicer::Key::R
#define OS_KEY_S               ::OSlicer::Key::S
#define OS_KEY_T               ::OSlicer::Key::T
#define OS_KEY_U               ::OSlicer::Key::U
#define OS_KEY_V               ::OSlicer::Key::V
#define OS_KEY_W               ::OSlicer::Key::W
#define OS_KEY_X               ::OSlicer::Key::X
#define OS_KEY_Y               ::OSlicer::Key::Y
#define OS_KEY_Z               ::OSlicer::Key::Z
#define OS_KEY_LEFT_BRACKET    ::OSlicer::Key::LeftBracket   /* [ */
#define OS_KEY_BACKSLASH       ::OSlicer::Key::Backslash     /* \ */
#define OS_KEY_RIGHT_BRACKET   ::OSlicer::Key::RightBracket  /* ] */
#define OS_KEY_GRAVE_ACCENT    ::OSlicer::Key::GraveAccent   /* ` */
#define OS_KEY_WORLD_1         ::OSlicer::Key::World1        /* non-US #1 */
#define OS_KEY_WORLD_2         ::OSlicer::Key::World2        /* non-US #2 */

/* Function keys */
#define OS_KEY_ESCAPE          ::OSlicer::Key::Escape
#define OS_KEY_ENTER           ::OSlicer::Key::Enter
#define OS_KEY_TAB             ::OSlicer::Key::Tab
#define OS_KEY_BACKSPACE       ::OSlicer::Key::Backspace
#define OS_KEY_INSERT          ::OSlicer::Key::Insert
#define OS_KEY_DELETE          ::OSlicer::Key::Delete
#define OS_KEY_RIGHT           ::OSlicer::Key::Right
#define OS_KEY_LEFT            ::OSlicer::Key::Left
#define OS_KEY_DOWN            ::OSlicer::Key::Down
#define OS_KEY_UP              ::OSlicer::Key::Up
#define OS_KEY_PAGE_UP         ::OSlicer::Key::PageUp
#define OS_KEY_PAGE_DOWN       ::OSlicer::Key::PageDown
#define OS_KEY_HOME            ::OSlicer::Key::Home
#define OS_KEY_END             ::OSlicer::Key::End
#define OS_KEY_CAPS_LOCK       ::OSlicer::Key::CapsLock
#define OS_KEY_SCROLL_LOCK     ::OSlicer::Key::ScrollLock
#define OS_KEY_NUM_LOCK        ::OSlicer::Key::NumLock
#define OS_KEY_PRINT_SCREEN    ::OSlicer::Key::PrintScreen
#define OS_KEY_PAUSE           ::OSlicer::Key::Pause
#define OS_KEY_F1              ::OSlicer::Key::F1
#define OS_KEY_F2              ::OSlicer::Key::F2
#define OS_KEY_F3              ::OSlicer::Key::F3
#define OS_KEY_F4              ::OSlicer::Key::F4
#define OS_KEY_F5              ::OSlicer::Key::F5
#define OS_KEY_F6              ::OSlicer::Key::F6
#define OS_KEY_F7              ::OSlicer::Key::F7
#define OS_KEY_F8              ::OSlicer::Key::F8
#define OS_KEY_F9              ::OSlicer::Key::F9
#define OS_KEY_F10             ::OSlicer::Key::F10
#define OS_KEY_F11             ::OSlicer::Key::F11
#define OS_KEY_F12             ::OSlicer::Key::F12
#define OS_KEY_F13             ::OSlicer::Key::F13
#define OS_KEY_F14             ::OSlicer::Key::F14
#define OS_KEY_F15             ::OSlicer::Key::F15
#define OS_KEY_F16             ::OSlicer::Key::F16
#define OS_KEY_F17             ::OSlicer::Key::F17
#define OS_KEY_F18             ::OSlicer::Key::F18
#define OS_KEY_F19             ::OSlicer::Key::F19
#define OS_KEY_F20             ::OSlicer::Key::F20
#define OS_KEY_F21             ::OSlicer::Key::F21
#define OS_KEY_F22             ::OSlicer::Key::F22
#define OS_KEY_F23             ::OSlicer::Key::F23
#define OS_KEY_F24             ::OSlicer::Key::F24
#define OS_KEY_F25             ::OSlicer::Key::F25

/* Keypad */
#define OS_KEY_KP_0            ::OSlicer::Key::KP0
#define OS_KEY_KP_1            ::OSlicer::Key::KP1
#define OS_KEY_KP_2            ::OSlicer::Key::KP2
#define OS_KEY_KP_3            ::OSlicer::Key::KP3
#define OS_KEY_KP_4            ::OSlicer::Key::KP4
#define OS_KEY_KP_5            ::OSlicer::Key::KP5
#define OS_KEY_KP_6            ::OSlicer::Key::KP6
#define OS_KEY_KP_7            ::OSlicer::Key::KP7
#define OS_KEY_KP_8            ::OSlicer::Key::KP8
#define OS_KEY_KP_9            ::OSlicer::Key::KP9
#define OS_KEY_KP_DECIMAL      ::OSlicer::Key::KPDecimal
#define OS_KEY_KP_DIVIDE       ::OSlicer::Key::KPDivide
#define OS_KEY_KP_MULTIPLY     ::OSlicer::Key::KPMultiply
#define OS_KEY_KP_SUBTRACT     ::OSlicer::Key::KPSubtract
#define OS_KEY_KP_ADD          ::OSlicer::Key::KPAdd
#define OS_KEY_KP_ENTER        ::OSlicer::Key::KPEnter
#define OS_KEY_KP_EQUAL        ::OSlicer::Key::KPEqual

#define OS_KEY_LEFT_SHIFT      ::OSlicer::Key::LeftShift
#define OS_KEY_LEFT_CONTROL    ::OSlicer::Key::LeftControl
#define OS_KEY_LEFT_ALT        ::OSlicer::Key::LeftAlt
#define OS_KEY_LEFT_SUPER      ::OSlicer::Key::LeftSuper
#define OS_KEY_RIGHT_SHIFT     ::OSlicer::Key::RightShift
#define OS_KEY_RIGHT_CONTROL   ::OSlicer::Key::RightControl
#define OS_KEY_RIGHT_ALT       ::OSlicer::Key::RightAlt
#define OS_KEY_RIGHT_SUPER     ::OSlicer::Key::RightSuper
#define OS_KEY_MENU            ::OSlicer::Key::Menu

// Mouse
#define OS_MOUSE_BUTTON_LEFT    ::OSlicer::Button::Left
#define OS_MOUSE_BUTTON_RIGHT   ::OSlicer::Button::Right
#define OS_MOUSE_BUTTON_MIDDLE  ::OSlicer::Button::Middle