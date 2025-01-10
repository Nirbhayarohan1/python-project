import kotlinx.serialization.Serializable

@Serializable
data class UserProfile(
    val id: Int,
    val name: String,
    val age: Int,
    val gender: String,
    val bio: String
)

@Serializable
data class SwipeRequest(
    val swiperId: Int,
    val swipedUserId: Int,
    val liked: Boolean
)

@Serializable
data class Match(
    val user1: UserProfile,
    val user2: UserProfile
)
