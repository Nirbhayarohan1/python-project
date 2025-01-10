import io.ktor.server.engine.*
import io.ktor.server.netty.*
import io.ktor.application.*
import io.ktor.features.ContentNegotiation
import io.ktor.serialization.*
import io.ktor.request.receive
import io.ktor.response.*
import io.ktor.routing.*

fun main() {
    embeddedServer(Netty, port = 8080) {
        install(ContentNegotiation) {
            json()
        }
        routing {
            val users = mutableListOf(
                UserProfile(1, "Alice", 25, "female", "Love hiking!"),
                UserProfile(2, "Bob", 27, "male", "Dog lover and foodie."),
                UserProfile(3, "Charlie", 24, "male", "Aspiring musician."),
                UserProfile(4, "Diana", 26, "female", "Tech enthusiast.")
            )

            val swipes = mutableListOf<Pair<Int, Int>>()

            get("/profiles") {
                call.respond(users)
            }

            post("/swipe") {
                val swipeRequest = call.receive<SwipeRequest>()
                val liked = swipeRequest.liked

                if (liked) {
                    swipes.add(Pair(swipeRequest.swiperId, swipeRequest.swipedUserId))

                    // Check if it's a match
                    val reverseSwipe = swipes.find { it.first == swipeRequest.swipedUserId && it.second == swipeRequest.swiperId }

                    if (reverseSwipe != null) {
                        val user1 = users.find { it.id == swipeRequest.swiperId }
                        val user2 = users.find { it.id == swipeRequest.swipedUserId }
                        if (user1 != null && user2 != null) {
                            call.respond(Match(user1, user2))
                        }
                    } else {
                        call.respond(mapOf("message" to "Swipe recorded"))
                    }
                } else {
                    call.respond(mapOf("message" to "Swipe recorded (disliked)"))
                }
            }
        }
    }.start(wait = true)
}
