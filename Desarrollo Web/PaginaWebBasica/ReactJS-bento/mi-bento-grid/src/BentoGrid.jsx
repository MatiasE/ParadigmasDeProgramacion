import { Star, ArrowUp } from 'lucide-react'

// Componente Card
const Card = ({ children, className }) => {
    return (
        <div className={`rounded-xl shadow-lg ${className}`}>
            {children}
        </div>
    );
};

function BentoGrid() {
    return (
        <>
            {/* Social Media 10x Faster Card */ }
            <Card className = "p-6 bg-[#7C3AED] text-white md:col-span-2" >
                <h1 className="text-3xl md:text-4xl font-bold mb-4">
                    Social Media <span className="text-[#FFB84C]">10x</span>
                    <br />
                    Faster with AI
                </h1>
                <div className="flex gap-1 mb-2">
                    {[...Array(5)].map((_, i) => (
                        <Star key={i} className="w-5 h-5 fill-[#FFB84C]" />
                    ))}
                </div>
                <p className="text-sm opacity-90">Over 4,000 5-star reviews</p>
            </Card >

            {/* Best Time to Post Card */ }
            <Card className = "p-6 bg-[#F3F0FF]" >
                <h3 className="text-xl font-bold mb-4">Best Time to Post</h3>
                <div className="space-y-4">
                    <div className="flex justify-between text-sm text-gray-600">
                        <span>Mon</span>
                        <span>Tue</span>
                        <span>Wed</span>
                        <span>Thu</span>
                        <span>Fri</span>
                    </div>
                    <div className="flex items-end justify-between gap-2 h-32">
                        {[40, 60, 100, 80, 50].map((height, i) => (
                            <div
                                key={i}
                                className="w-8 bg-purple-500 rounded-full"
                                style={{ height: `${height}%` }}
                            />
                        ))}
                    </div>
                    <div className="flex justify-between text-xs text-gray-500">
                        <span>12a</span>
                        <span>3a</span>
                        <span>6a</span>
                        <span>9a</span>
                        <span>12p</span>
                    </div>
                </div>
            </Card >

            {/* Manage Multiple Accounts Card */ }
            <Card className = "p-6" >
                <h3 className="text-xl font-bold mb-4">
                    Manage multiple accounts and platforms.
                </h3>
                <div className="flex gap-2">
                    <div className="w-8 h-8 bg-gradient-to-tr from-purple-600 to-pink-500 rounded-full" />
                    <div className="w-8 h-8 bg-blue-400 rounded-full" />
                </div>
            </Card >

            {/* AI Writing Card */ }
            < Card className = "p-6 bg-[#FFB84C]" >
                <h3 className="text-xl font-bold mb-4">
                    Write your content using AI.
                </h3>
                <div className="bg-white p-4 rounded-lg">
                    <p className="text-sm text-gray-600">
                        "Give me 5 tips to grow my follower on Insta!"
                    </p>
                </div>
            </Card >

            {/* Growth Stats Card */ }
            < Card className = "p-6 bg-[#7C3AED] text-white md:col-span-2" >
                <div className="flex justify-between items-center mb-4">
                    <h3 className="text-2xl font-bold">Grow followers with non-stop content.</h3>
                    <div className="bg-white/20 px-3 py-1 rounded-full">
                        <span className="text-sm flex items-center gap-1">
                            <ArrowUp className="w-4 h-4" />
                            +40%
                        </span>
                    </div>
                </div>
                <div className="h-24 flex items-end gap-2">
                    {[30, 45, 60, 80, 70].map((height, i) => (
                        <div
                            key={i}
                            className="flex-1 bg-white/20 rounded-t-lg"
                            style={{ height: `${height}%` }}
                        />
                    ))}
                </div>
            </Card>
        </>
);
}

export default BentoGrid;